# Proximi.io Processor

[![CI Status](https://img.shields.io/travis/Matteo Crippa/ProximiioProcessor.svg?style=flat)](https://travis-ci.org/Matteo Crippa/ProximiioProcessor)
[![Version](https://img.shields.io/cocoapods/v/ProximiioProcessor.svg?style=flat)](https://cocoapods.org/pods/ProximiioProcessor)
[![License](https://img.shields.io/cocoapods/l/ProximiioProcessor.svg?style=flat)](https://cocoapods.org/pods/ProximiioProcessor)
[![Platform](https://img.shields.io/cocoapods/p/ProximiioProcessor.svg?style=flat)](https://cocoapods.org/pods/ProximiioProcessor)

## Example

This framework provide easy position processor for [Proximi.io SDK](https://proximi.io), actually only beta SDK support processors.

Actually are supported:

- PDR (Pedestrian Dead Reck) - `ProximiioPDRProcessor`
- Position Snap - `ProximiioSnapProcessor`

Each processor is complain to _SDK_ protocol of type `ProximiioLocationProcessor`.

In order to use you can for example:

```swift
/// add snap pre-processor
let snap = ProximiioSnapProcessor()
snap.threshold = 5.0
Proximiio.sharedInstance()?.locationManager.addProcessor(snap, avoidDuplicates: true)
        
/// add pdr processor
let prd = ProximiioSnapProcessor()
pdr.threshold = 15.0
pdr.avgStepLength = 0.65
pdr.useDeviceHeading = false
Proximiio.sharedInstance()?.locationManager.addProcessor(pdrProcessor, avoidDuplicates: true)
```

## Parameters

Each processor has specific parameters to manage them.

`ProximiioPDRProcessor`

- `threshold`, set distance till user can get far from first position fix (aka position from an hardware source) till this can be fixed again
- `avgStepLenght`, in meters define the average step length
- `useDeviceHeading`, define if the heading for the step is calculate by the sensors automatically or feeded manually by `customHeading`
- `customHeading`, need to have the actual heading position to calculate the step

`ProximiioSnapProcessor`

- `threshold`, set distance till the user is attracted to a path defined in the backend

## Requirements

## Installation

ProximiioProcessor is available through [CocoaPods](https://cocoapods.org). To install
it, simply add the following line to your Podfile:

```ruby
pod 'ProximiioProcessor'
```

## Author

Proximi.io, support@proximi.io

## License

ProximiioProcessor is available under the commercial license. See the LICENSE file for more info.
