<?php

/**
 * @file
 * Callbacks for administrative pages.
 */

/**
 * Form callback
 */
function addressfield_validation_settings_form($form, &$form_state) {

  $provider_coll = addressfield_validation_get_providers();
  $provider_opts = array();
  foreach ($provider_coll as $provider_key => $provider_defi) {
    $provider_opts[$provider_key] = $provider_defi['title'];
  }

  $form['addressfield_validation_provider'] = array(
    '#title' => t('Validation provider'),
    '#description' => t('Choose an address field validation provider.'),
    '#type' => 'select',
    '#options' => $provider_opts,
    '#default_value' => variable_get('addressfield_validation_provider'),
  );

  return system_settings_form($form);

}