<?php

/**
 * @file
 * FedEx AVS admin page callbacks.
 */

/**
 * Form callback.
 */
function fedex_avs_settings_form($form, &$form_state) {
  
  $form['fedex_avs_environment'] = array(
    '#title' => t('Environment'),
    '#type' => 'radios',
    '#options' => array(
      'test' => t('Test'),
      'live' => t('Live'),
    ),
    '#default_value' => variable_get('fedex_avs_environment', 'test'),
  );
  $form['test'] = array(
    '#type' => 'fieldset',
    '#title' => t('Test settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['live'] = array(
    '#type' => 'fieldset',
    '#title' => t('Live settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  // Create same set of config fields for each environment
  $field_coll = array(
    'key' => array(
      '#title' => t('Key'),
      '#type' => 'textfield',
    ),
    'account' => array(
      '#title' => t('Account number'),
      '#type' => 'textfield',
    ),
    'meter' => array(
      '#title' => t('Meter number'),
      '#type' => 'textfield',
    ),
    'password' => array(
      '#title' => t('Password'),
      '#type' => 'textfield',
    ),
    'street_accuracy' => array(
      '#title' => t('Street accuracy'),
      '#type' => 'select',
      '#options' => array(
        'LOOSE' => 'LOOSE',
        'MEDIUM' => 'MEDIUM',
        'TIGHT' => 'TIGHT',
        'EXACT' => 'EXACT',
      ),
    ),
    'directional_accuracy' => array(
      '#title' => t('Directional accuracy'),
      '#type' => 'select',
      '#options' => array(
        'LOOSE' => 'LOOSE',
        'MEDIUM' => 'MEDIUM',
        'TIGHT' => 'TIGHT',
        'EXACT' => 'EXACT',
      ),
    ),
  );
  foreach (array('test', 'live') as $environment) {
    foreach ($field_coll as $field_key => $field_defi) {
      $field_key = 'fedex_avs_' . $environment . '_' . $field_key;
      $field_defi['#default_value'] = variable_get($field_key);
      $form[$environment][$field_key] = $field_defi;
    }
  }

  return system_settings_form($form);

}