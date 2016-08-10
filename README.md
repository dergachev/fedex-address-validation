# fedex-address-validation

Demo Drupal Commerce site that utilizes the FedEx Address Validation Web service.

INSTALLATION

- Download the files and do a standard Drupal installation.
- Setup a Drupal Commerce environment with the following steps:
  + Install features_commerce module
  + Install and configure the fedex_avs module following the it's readme file.
  + Install and configure the fedex_avs_addressfield module following the it's
	  readme file.

TESTING

- Configure the shipping address field in customer profile and enable
  FedEx Address Validation (at least for the commerce_checkout_form_checkout form).
- Create some products from the page:
  Store > Products > Add a Product
- Create display pages for test products from the page:
  Content > Add content > Offering
- Add a product to your cart and attempt to check out. During checkout,
  if you enter a wrong shipping address, you will be presented with validation
  error messages provided by the FedEx AVS. You can then choose to correct 
  your address as hinted by the error messages or choose to ignore validation
  and proceed.

DEMO NOTES

 - URL: http://evowebfedexaddvalvuiwpzfutf.devcloud.acquia-sites.com/
 - User: root

TASK NOTES

FedEx has a bunch of web services available, see here: http://www.fedex.com/us/developer/web-services/index.html . The one we're interested in is called "Address Validation". It lets you check if an address seems valid for shipping. We'd like to prototype this, so we can see if it makes sense to integrate into Gene Tools.
Here are the steps you'll need to do:

Configure a brand new basic site with Drupal Commerce and the commerce_shipping module. Make sure you're able to check out an order, and set a shipping address when you do so. Put the resulting git repository and database somewhere so we can reproduce it.
Build a small Drupal module fedex_address_validation that allows you to communicate with the FedEx Address Validation service.
Build another small module address_validation that integrates fedex_address_validation with Drupal. When a user is checking out and gives Drupal their shipping address, this module should check that the address is valid. If it's not valid, the module should prevent the user from continuing checkout until they fix the shipping address.
Make sure you document what you've done. Also document how you tested your work.
