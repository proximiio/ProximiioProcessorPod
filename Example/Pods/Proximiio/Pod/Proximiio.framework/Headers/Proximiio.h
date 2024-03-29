//
//  Proximiio.h
//
//
//  Created by Proximi.io Developer Team 23/06/16.
//  Copyright © 2016 Proximi.io. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Proximiio/ProximiioLocation.h>
#import <Proximiio/ProximiioLocationSource.h>
#import <Proximiio/ProximiioState.h>
#import <Proximiio/ProximiioMode.h>
#import <Proximiio/ProximiioGeofence.h>
#import <Proximiio/ProximiioIBeacon.h>
#import <Proximiio/ProximiioEddystoneBeacon.h>
#import <Proximiio/ProximiioInput.h>
#import <Proximiio/ProximiioAPIResult.h>
#import <Proximiio/ProximiioResourceManager.h>
#import <Proximiio/ProximiioInputType.h>
#import <Proximiio/ProximiioCustomLocation.h>
#import <Proximiio/ProximiioBufferSize.h>
#import <Proximiio/ProximiioEventType.h>


//! Project version number for Proximiio.
FOUNDATION_EXPORT double ProximiioVersionNumber;

//! Project version string for Proximiio.
FOUNDATION_EXPORT const unsigned char ProximiioVersionString[];

@interface Proximiio : NSObject

- (void)requestPermissions;
- (id)initWithDelegate:(id)delegate token:(NSString *)token;
- (id)initWithDelegate:(id)delegate email:(NSString *)email password:(NSString *)password;
- (void)startUpdating;
- (void)stopUpdating;
- (void)extendBackgroundTime;
- (NSArray *)geofencesForLocation:(ProximiioLocation *)location;

+ (NSString *)visitorId;
- (ProximiioLocation *)lastLocation;

- (void)setBufferSize:(ProximiioBufferSize)bufferSize;

- (void)authWithToken:(NSString *)token callback:(void (^)(ProximiioState result))callback;
- (void)authWithEmail:(NSString *)email password:(NSString *)password callback:(void (^)(ProximiioState result))callback;

- (void)registerWithEmail:(NSString *)email
                 password:(NSString *)password
                firstName:(NSString *)firstName
                 lastName:(NSString *)lastName
                  company:(NSString *)company
               background:(NSString *)background
                  country:(NSString *)country
                 callback:(void (^)(ProximiioState result))callback;

- (void)resetAndRefresh;

- (void)setUpdateInterval:(double)updateInterval;
- (void)addCustomiBeaconUUID:(NSString*)uuid;
- (void)enable;
- (void)disable;
- (void)selectApplication:(NSString *)uuid;
- (ProximiioApplication *)application;
+ (Proximiio*)sharedInstance;
- (CBManagerState)btState;

- (ProximiioFloor*)currentFloor;

- (NSString*)token;

- (void)handlePush:(NSString *)title;
- (void)handleOutput:(NSObject *)payload;
- (void)handleFloorChange:(ProximiioFloor *)floor;

@property (weak) id delegate;
@property (nonatomic, strong) NSString *visitorId;
@property (readonly) BOOL remoteMode;

// management methods

-(NSArray *)places;
-(NSArray *)floors;
-(NSArray *)departments;
-(NSArray *)geofences;
-(NSArray *)applications;

- (BOOL)addPlace:(NSString *)name location:(CLLocationCoordinate2D)location
         address:(NSString *)address
indoorAtlasVenueID:(NSString *)indoorAtlasVenueId
            tags:(NSArray *)tags
    withCallback:(void (^)(BOOL success, NSError* error))callback;

- (BOOL)addFloor:(NSString*)name
         floorID:(NSString*)floorID
     floorPlanID:(NSString*)floorPlanID
           place:(ProximiioPlace*)place
     floorNumber:(NSNumber*)floorNumber
    withCallback:(void (^)(BOOL success, NSError* error))callback;

- (BOOL)addDepartment:(NSString*)name
                floor:(ProximiioFloor*)floor
                 tags:(NSArray*)tags
         withCallback:(void (^)(BOOL success, NSError* error))callback;

- (BOOL)addGeofence:(NSString*)name
         department:(ProximiioDepartment*)department
           location:(CLLocationCoordinate2D)location
             radius:(double)radius
            address:(NSString*)address 
       withCallback:(void (^)(BOOL success, NSError* error))callback;

- (BOOL)addiBeaconInput:(NSString*)name
             department:(ProximiioDepartment*)department
               location:(CLLocationCoordinate2D)location
                   uuid:(NSString*)uuid
                  major:(int)major
                  minor:(int)minor
           withCallback:(void (^)(BOOL success, NSError* error))callback;

- (BOOL)addEddystoneInput:(NSString*)name
               department:(ProximiioDepartment*)department
                 location:(CLLocationCoordinate2D)location
              namespaceID:(NSString*)namespaceID
               instanceID:(NSString*)instanceID
             withCallback:(void (^)(BOOL success, NSError* error))callback;

- (BOOL)addCustomInput:(NSString*)name
            department:(ProximiioDepartment*)department
              location:(CLLocationCoordinate2D)location
          withCallback:(void (^)(BOOL success, NSError* error))callback;

- (BOOL)addApplication:(NSString*)name
            eddystones:(BOOL)eddystones
              iBeacons:(BOOL)iBeacons
           indoorAtlas:(BOOL)indoorAtlas
     indoorAtlasApiKey:(NSString*)iaApiKey 
indoorAtlasApiKeySecret:(NSString*)iaApiKeySecret
       nativeGeofences:(BOOL)nativeGeofences
             steerPath:(BOOL)steerPath
          steerPathNDD:(NSString*)steerPathNDD
          withCallback:(void (^)(BOOL success, NSError* error))callback;

- (BOOL)updatePlace:(NSString *)uuid
               name:(NSString *)name
           location:(CLLocationCoordinate2D)location
            address:(NSString *)address
 indoorAtlasVenueID:(NSString *)indoorAtlasVenueId
               tags:(NSArray *)tags
       withCallback:(void (^)(BOOL success, NSError* error))callback;

- (BOOL)updateFloor:(NSString*)ID
               name:(NSString*)name            
        floorPlanID:(NSString*)floorPlanID
              place:(ProximiioPlace*)place 
        floorNumber:(NSNumber*)floorNumber 
       withCallback:(void (^)(BOOL success, NSError* error))callback;

- (BOOL)updateDepartment:(NSString*)ID
                    name:(NSString*)name
                   floor:(ProximiioFloor*)floor
                    tags:(NSArray*)tags
            withCallback:(void (^)(BOOL success, NSError* error))callback;

- (BOOL)updateGeofence:(NSString*)ID
                  name:(NSString*)name
            department:(ProximiioDepartment*)department
              location:(CLLocationCoordinate2D)location
                radius:(double)radius
               address:(NSString*)address
          withCallback:(void (^)(BOOL success, NSError* error))callback;

- (BOOL)updateiBeaconInput:(NSString*)ID
                      name:(NSString*)name
                department:(ProximiioDepartment*)department
                  location:(CLLocationCoordinate2D)location
                      uuid:(NSString*)uuid
                     major:(int)major
                     minor:(int)minor 
       triggersFloorChange:(BOOL)triggersFloorChange
       triggersPlaceChange:(BOOL)triggersPlaceChange
                   floorID:(NSString*)floorID
                   placeID:(NSString*)placeID
              withCallback:(void (^)(BOOL success, NSError* error))callback;

- (BOOL)updateEddystoneInput:(NSString*)ID
                        name:(NSString*)name
                  department:(ProximiioDepartment*)department
                    location:(CLLocationCoordinate2D)location
                 namespaceID:(NSString*)namespaceID
                  instanceID:(NSString*)instanceID
         triggersFloorChange:(BOOL)triggersFloorChange
         triggersPlaceChange:(BOOL)triggersPlaceChange
                     floorID:(NSString*)floorID
                     placeID:(NSString*)placeID
                withCallback:(void (^)(BOOL success, NSError* error))callback;

- (BOOL)updateCustomInput:(NSString*)ID
                     name:(NSString*)name
               department:(ProximiioDepartment*)department
                 location:(CLLocationCoordinate2D)location
      triggersFloorChange:(BOOL)triggersFloorChange
      triggersPlaceChange:(BOOL)triggersPlaceChange
                  floorID:(NSString*)floorID
                  placeID:(NSString*)placeID
             withCallback:(void (^)(BOOL success, NSError* error))callback;

- (BOOL)updateApplication:(NSString*)ID
                     name:(NSString*)name
               eddystones:(BOOL)eddystones
                 iBeacons:(BOOL)iBeacons
              indoorAtlas:(BOOL)indoorAtlas
        indoorAtlasApiKey:(NSString*)iaApiKey
  indoorAtlasApiKeySecret:(NSString*)iaApiKeySecret
          nativeGeofences:(BOOL)nativeGeofences
                steerPath:(BOOL)steerPath
             steerPathNDD:(NSString*)steerPathNDD
             withCallback:(void (^)(BOOL success, NSError* error))callback;

- (void)deletePlace:(NSString *)uuid withCallback:(void (^)(BOOL success, NSError* error))callback;
- (void)deleteFloor:(NSString *)uuid withCallback:(void (^)(BOOL success, NSError* error))callback;
- (void)deleteDepartment:(NSString *)uuid withCallback:(void (^)(BOOL success, NSError* error))callback;
- (void)deleteGeofence:(NSString *)uuid withCallback:(void (^)(BOOL success, NSError* error))callback;
- (void)deleteInput:(NSString *)uuid withCallback:(void (^)(BOOL success, NSError* error))callback;

@end

@protocol ProximiioDelegate

@optional

- (void)proximiioPositionUpdated:(ProximiioLocation *)location;
- (void)proximiioEnteredGeofence:(ProximiioGeofence *)geofence;
- (void)proximiioExitedGeofence:(ProximiioGeofence *)geofence;
- (void)proximiioFloorChanged:(ProximiioFloor *)floor;
- (void)proximiioFoundiBeacon:(ProximiioIBeacon *)beacon;
- (void)proximiioUpdatediBeacon:(ProximiioIBeacon *)beacon;
- (void)proximiioLostiBeacon:(ProximiioIBeacon *)beacon;
- (void)proximiioFoundEddystoneBeacon:(ProximiioEddystoneBeacon *)beacon;
- (void)proximiioUpdatedEddystoneBeacon:(ProximiioEddystoneBeacon *)beacon;
- (void)proximiioLostEddystoneBeacon:(ProximiioEddystoneBeacon *)beacon;

- (BOOL)proximiioHandlePushMessage:(NSString*)title;
- (void)proximiioHandleOutput:(NSObject*)payload;
- (NSDictionary*)proximiioProvideMetadataForEventWithType:(ProximiioEventType)eventType geofence:(ProximiioGeofence*)geofence location:(ProximiioLocation *)location;

- (void)onProximiioReady;
- (void)onProximiioAuthorizationInvalid;
- (void)onProximiioAuthorizationFailure;
- (void)proximiioCentralManagerDidUpdateState;
- (void)proximiioUpdatedApplications;
- (void)proximiioUpdatedDepartments;
- (void)proximiioUpdatedFloors;
- (void)proximiioUpdatedInputs;
- (void)proximiioUpdatedPlaces;
- (void)proximiioUpdatedGeofences;

@end
