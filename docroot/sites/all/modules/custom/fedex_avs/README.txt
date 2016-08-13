DESCRIPTION

This module uses the FedEx AVS to detect if an address entered by a user
can be mapped to a valid address in the FedEx database. However, it mainly validates
the format of the address and certain other details only.

FedEx AVS sometimes makes certain changes to the input address to standardize
the same and conduct the validation. However, at the moment, the module does not
handle these changes / standardizations. Example, the user enters a postal code
for Montreal but enters city as Vancouver. FedEx understands that the City is 
Montreal using the postal code. This can be resolved in a future version where the 
user will be shown the address as interpreted by FedEx (effective address) and 
will be asked to confirm it or make changes to his input as the case may be.

INSTALLATION

- Install the module just like you would any other module.
- Obtain a FedEx test/live key at https://www.fedex.com/login/web/jsp/logon.jsp.
- Enter your FedEx API credentials on the module configuration page.

NOTE: This is an API module and does not add any special functionality to your
site out of the box. To make use of this module, install other modules which depend
on this module to actually provide some new functionality.