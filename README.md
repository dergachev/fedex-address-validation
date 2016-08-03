# fedex-address-validation

Demo Drupal Commerce site that utilizes the FedEx Address Validation Web service.

Task notes:

* FedEx has a bunch of web services available, see here: http://www.fedex.com/us/developer/web-services/index.html . The one we're interested in is called "Address Validation". It lets you check if an address seems valid for shipping. We'd like to prototype this, so we can see if it makes sense to integrate into Gene Tools.

Here are the steps you'll need to do:

* Configure a brand new basic site with Drupal Commerce and the commerce_shipping module. Make sure you're able to check out an order, and set a shipping address when you do so. Put the resulting git repository and database somewhere so we can reproduce it.
* Build a small Drupal module fedex_address_validation that allows you to communicate with the FedEx Address Validation service.
* Build another small module address_validation that integrates fedex_address_validation with Drupal. When a user is checking out and gives Drupal their shipping address, this module should check that the address is valid. If it's not valid, the module should prevent the user from continuing checkout until they fix the shipping address.
* Make sure you document what you've done. Also document how you tested your work.
