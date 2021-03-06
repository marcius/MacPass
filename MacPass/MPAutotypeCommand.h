//
//  MPAutotypeCommand.h
//  MacPass
//
//  Created by Michael Starke on 10/11/13.
//  Copyright (c) 2013 HicknHack Software GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString *const kMPAutotypeSymbolShift;
extern NSString *const kMPAutotypeSymbolControl;
extern NSString *const kMPAutotypeSymbolAlt;
extern NSString *const kMPAutotypeSymbolEnter;
extern NSString *const kMPAutptypeCommandEnter;

@class KPKEntry;

/**
 *  The Autotype command reperesent a capsualted Action that was determined by interpreting
 *  Autotype field for a given entry. This is a class cluster and schould be considered the sole
 *  enty point for creating AutotypeCommands.
 */
@interface MPAutotypeCommand : NSObject

@property (readonly, copy) NSString *commandString;
/**
 *  Determines the Keycode for the given keyboard layout for the supplied character
 *
 *  @param uchrHeader The KeyboardLayout
 *  @param character  The Character that needs to be pressed
 *
 *  @return Key code in the supplied keyboard layout
 */
- (CGKeyCode)keyCodeForKeyboard:(const UCKeyboardLayout *)uchrHeader character:(NSString *)character;
/**
 *  Sends a KeyPress Event with the supplied modifier flags and Keycode
 *  Any existing modifiers will be disabled for this event. If the user
 *  presses any key, those will be ignored during this event
 *
 *  @param keyCode virtual KeyCode to be sent
 *  @param flags   modifier flags for the key press event
 */
- (void)sendPressKey:(CGKeyCode)keyCode modifierFlags:(CGEventFlags)flags;

/**
 *  Convenience message to be sent for executing a simple paste command
 */
- (void)sendPasteKeyCode;

/**
 *  Exectues the Autotype Command. This will be called by the autotype daemon.
 */
- (void)executeWithEntry:(KPKEntry *)entry;

@end
