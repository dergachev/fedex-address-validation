<?php
/**
 * @file
 * features_commerce.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function features_commerce_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-offering-body'.
  $field_instances['node-offering-body'] = array(
    'bundle' => 'offering',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'trim_length' => 600,
        ),
        'type' => 'text_summary_or_trimmed',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'body',
    'label' => 'Body',
    'required' => FALSE,
    'settings' => array(
      'display_summary' => TRUE,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'rows' => 20,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'node-offering-field_product'.
  $field_instances['node-offering-field_product'] = array(
    'bundle' => 'offering',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'commerce_cart',
        'settings' => array(
          'combine' => TRUE,
          'default_quantity' => 1,
          'line_item_type' => 'product',
          'show_quantity' => FALSE,
          'show_single_product_attributes' => FALSE,
        ),
        'type' => 'commerce_cart_add_to_cart_form',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'commerce_cart',
        'settings' => array(
          'combine' => TRUE,
          'default_quantity' => 1,
          'line_item_type' => 'product',
          'show_quantity' => FALSE,
          'show_single_product_attributes' => FALSE,
        ),
        'type' => 'commerce_cart_add_to_cart_form',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_product',
    'label' => 'Product',
    'required' => 1,
    'settings' => array(
      'field_injection' => 1,
      'referenceable_types' => array(
        'product' => 0,
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'commerce_product_reference',
      'settings' => array(
        'autocomplete_match' => 'contains',
        'autocomplete_path' => 'commerce_product/autocomplete',
        'size' => 60,
      ),
      'type' => 'commerce_product_reference_autocomplete',
      'weight' => 2,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Body');
  t('Product');

  return $field_instances;
}