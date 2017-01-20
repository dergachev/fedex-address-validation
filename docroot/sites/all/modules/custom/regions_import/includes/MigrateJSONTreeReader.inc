<?php

/**
 * @file
 * Support for migration of JSON sources with tree-type data structure.
 */

/**
 * An extension of MigrateJSONReader with the ability to iterate of
 * items with multiple levels of child items. e.g.:
 * [{"id":"in","name":"India", "children": [{"id": "wb", "name": "West Bengal"}, ...]}]
 */
class MigrateJSONTreeReader extends MigrateJSONReader {
  
  /**
   * Name of the property containing the children data.
   * @var string
   */
  protected $childrenField = 'children';
  
  /**
   * Collection of all unprocessed descendants of the current top-level node.
   * @var array
   */
  protected $childrenQueue = array();

  /**
   * An index of all nodes whose children have been processed.
   * @var array
   */
  protected $childrenProcessed = array();

  /**
   * Sets the name of the field which contains
   * @param string $name
   */
  public function setChildrenField($name) {
    $this->childrenField = $name;
  }

  public function next() {
    
    $currentElement = $this->currentElement;
    $currentId = $this->currentId;
    $childrenField = $this->childrenField;
    
    // If the current node has unparsed children, queue up all
    // the descendants recursively. This part will only work for top-level
    // items because all descendants' children would be marked as "processed"
    // as soon as they are discovered.
    if ($currentElement && isset ($currentElement->$childrenField) && !isset ($this->childrenProcessed[$currentId])) {
      $descendants = $this->getRecordDescendants($currentElement);
      if (sizeof($descendants) > 0) {
        foreach ($descendants as $descendant) {
          $this->childrenProcessed[$descendant->{$this->idField}] = TRUE;
          $this->childrenQueue[] = $descendant;
        }
      }
      $this->childrenProcessed[$currentId] = TRUE;
    }
    
    // If we have children in the queue, iterate over them first.
    // This will result in covering all items for the current top-level node.
    // So the pointer will move to "us" only after "ca" and all it's desencants
    // have been iterated through.
    if ($child = array_shift($this->childrenQueue)) {
      $this->currentElement = $child;
      $this->currentId = $child->{$this->idField};
    }
    // If current top-level node has no more children in the queue,
    // We move to the next top-level node.
    else {
      parent::next();
    }
    
  }
  
  public function rewind() {
    $this->childrenQueue = array();
    $this->childrenProcessed = array();
    parent::rewind();
  }
  
  /**
   * Returns an array containing all the descendants of a node.
   * @param StdClass $record
   * @return array An array of all descendant nodes of $record.
   * Every child node has a property named "parent" denoting the
   * parent identifier.
   */
  protected function getRecordDescendants(StdClass $record) {

    $childrenField = $this->childrenField;

    $output = array();
    if (isset ($record->$childrenField)) {
      foreach ($record->$childrenField as $child) {
        
        // Process this child
        $child->parent = $record->{$this->idField};
        $output[] = $child;
        
        // Process grand children
        $grandchildren = $this->getRecordDescendants($child);
        if (sizeof($grandchildren) > 0) {
          $output = array_merge($output, $grandchildren);
        }
        
      }
    }
    return $output;

  }
  
}
