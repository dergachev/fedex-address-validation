<?php

/**
 * @file
 * Address field validation
 */

$plugin = array(
  'title' => t('Validate address as per global configuration'),
  'format callback' => 'addressfield_validation_format_callback',
  'type' => 'address',
  'weight' => -100,
);

/**
 * Format callback.
 *
 * @see CALLBACK_addressfield_validate_callback()
 */
function addressfield_validation_format_callback(&$format, $address, $context = array()) {
  if ($context['mode'] == 'form') {
    $format['#element_validate'][] = 'addressfield_validation_element_validate';
  }
}
