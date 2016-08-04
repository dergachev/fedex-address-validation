<?php
/**
 * @file
 * features_commerce.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function features_commerce_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function features_commerce_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function features_commerce_node_info() {
  $items = array(
    'offering' => array(
      'name' => t('Offering'),
      'base' => 'node_content',
      'description' => t('Use <em>Offering</em> to manage product displays on your site.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
