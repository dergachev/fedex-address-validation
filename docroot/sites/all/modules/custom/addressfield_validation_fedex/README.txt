DESCRIPTION

This module uses the FedEx AVS to detect if an address entered by a user
can be mapped to a valid address in their database. However, it mainly validates
the format of the address and certain other details at the moment.

FedEx AVS sometimes makes certain changes to the input address to standardize
the same and conduct the validation. However, at the moment, the module does not
handle these changes / standardizations. Example, the user enters a postal code
for Montreal but enters city as Vancouver. FedEx understands that the City is 
Montreal using the postal code. This can be resolved in a future version where the 
user will be shown the address as interpreted by FedEx (effective address) and 
will be asked to confirm it or make changes to his input as the case may be.

INSTALLATION

# To install this module, first you need the addressfield_validation module.
# Obtain a FedEx test/live key at https://www.fedex.com/login/web/jsp/logon.jsp.
# Enter your FedEx API credentials on the following page:
  Admin > Config > People > Address Field Validation > FedEx AVS
# Now, when you enter addresses, they will be validated using the FedEx AVS.
  - Currently, the module only checks if FedEx could interpret the address as valid.