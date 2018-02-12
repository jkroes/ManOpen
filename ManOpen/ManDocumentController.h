
#import "ManOpenProtocol.h"
#import "SystemType.h"
#import <AppKit/NSDocumentController.h>


@class NSPanel, NSTextField, NSPopUpButton, NSFont;
@class NSData, NSMutableString;


extern NSArray *GetWordArray(NSString *string);


@interface ManDocumentController : NSDocumentController <ManOpen>
{
    IBOutlet NSPanel *openTextPanel;
    IBOutlet NSPanel *aproposPanel;
    IBOutlet NSPanel *infoPanel;
    IBOutlet NSPanel *helpPanel;
    IBOutlet NSTextField *aproposField;
    IBOutlet NSTextField *openTextField;
    IBOutlet NSPopUpButton *openSectionPopup;
    BOOL startedUp;
}

- (id)openWord:(NSString *)word;

- (oneway void)openString:(NSString *)string;
- (oneway void)openString:(NSString *)string oneWordOnly:(BOOL)oneOnly;
- (oneway void)openApropos:(NSString *)apropos;

- (IBAction)openSection:(id)sender;
- (IBAction)openTextPanel:(id)sender;
- (IBAction)openAproposPanel:(id)sender;
- (IBAction)okApropos:(id)sender;
- (IBAction)okText:(id)sender;
- (IBAction)cancelText:(id)sender;

- (IBAction)orderFrontHelpPanel:(id)sender;
- (IBAction)orderFrontPreferencesPanel:(id)sender;

// Helper methods for document classes
- (NSMutableString *)manCommandWithManPath:(NSString *)manPath;
- (NSData *)dataByExecutingCommand:(NSString *)command;
- (NSData *)dataByExecutingCommand:(NSString *)command manPath:(NSString *)manPath;

@end
