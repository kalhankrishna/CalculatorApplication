# CalculatorApplication
A Calculator application utilizing MFC

To successfully run this application, build the MathFunctions project first.
This will generate the required MathFunctions.dll which you can then place
in the output directory of the CalculatorApplication as per your requirements
and configuration. Doing this will dynamically load the dll at runtime for the app to use.

NOTE: The Application searches for "UseCButton" in "HKEY_LOCAL_USER\\SOFTWARE\\CalculatorApplication".
