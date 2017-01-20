<?php

/**
 * @file
 * Implements migration of region data into taxonomy terms,
 * preserving, hierarchies.
 */

class RegionImportTermMigration extends RegionImportAbstractMigration {

  public function __construct($arguments = array()) {
    
    parent::__construct($arguments);

    $this->description = t('Migrate region term data from JSON file.');

    // Define source
    $source_uri = DRUPAL_ROOT . '/' . drupal_get_path('module', 'regions_import') . '/regions.tree.json';
    $this->source = new MigrateSourceJSON($source_uri, 'path', array(
      'path' => 'Unique ID',
      'path_prefixed' => 'URL alias derived from ID',
      'name' => 'Name of the region',
      'parent' => 'Parent ID',
    ), array(
      'reader_class' => 'MigrateJSONTreeReader',
    ));
    
    // Define destination
    $this->destination = new MigrateDestinationTerm('regions');
    
    // Add mappings
    $this->map = new MigrateSQLMap($this->machineName, array(
      'path' => array(
        'type' => 'varchar',
        'length' => '128',
        'not null' => TRUE,
        'description' => 'Unique region path.',
      ),
    ), MigrateDestinationNode::getKeySchema());
    
    $this->addSimpleMappings(array('name'));
    
    $this->addFieldMapping('path', 'path_prefixed')
      ->description(t('Add regions/* path as the url alias.'));
    
    // Add parent data
    $this->addFieldMapping('parent', 'parent')
      ->sourceMigration($this->getMachineName())
      ->description(t('Inherit parent data as defined in JSON.'))
      ->defaultValue(NULL);
    
    $this->addUnmigratedDestinations(array('description', 'parent_name', 'format', 'weight'));
    
  }
  
  public function prepareRow($row) {
    
    parent::prepareRow($row);
    
    // Enforce path pattern regions/*
    // We do not overwrite the "path" property because it is used as a primary
    // key for the source and it plays a vital role in parent-determination
    $row->path_prefixed = 'regions/' . $row->path;
    
  }

}
