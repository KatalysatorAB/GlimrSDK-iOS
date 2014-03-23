KatalysatorSDK Readme
==========

###Minimum Setup for the Integration

- Add the KatalysatorSDK.framework and the KatalysatorSDKResources.bundle to your project
- In your Build Settings, search for Other Linker Flags and add "-ObjC" and "-all_load"
- Add CoreLocation.framework to the linked frameworks
- Add the KatalysatorSDK sample snippet and adjust the parameters according to your needs

###Usage
- The content is configured on the backend, see developer.katalysator.io
- The default sample provides a simple trigger when the user "Enters/Exits" the beacon range

For documentation visit developer.katalysator.io. 

###Changelog
02/11/2013 - v1.0.0b - Initial release ready for testing