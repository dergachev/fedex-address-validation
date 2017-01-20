<?php

/**
 * @file
 * Implements migrate API hooks.
 */

/**
 * Implements hook_migrate_api();
 */
function regions_import_migrate_api() {

  $output = array(
    'api' => 2,
    'groups' => array(
      'regions' => array(
        'title' => t('Region Imports'),
      )
    ),
    'migrations' => array(
      'RegionTerm' => array(
        'class_name' => 'RegionImportTermMigration',
        'group_name' => 'regions',
      ),
    ),
  );
  
  return $output;
  
}
