<?php

/**
 * @file
 * Defines common functionalities and utility methods for Migrations.
 * Actual migrations can extend the RegionImportAbstractMigration to
 * make use of these functionalities.
 */

abstract class RegionImportAbstractMigration extends Migration {
  
  public function __construct($arguments = array()) {
    parent::__construct($arguments);
    
    $this->team = array(
      new MigrateTeamMember('Jerry Radwick', 'jigar.m1987@gmail.com', t('Developer')),
    );
    
  }
  
}