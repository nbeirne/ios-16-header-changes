//
//  SWHighlightCenter.h
//  SWHighlightCenter
//
//  Copyright (c) 2021 Apple. All rights reserved.
//
#import <Foundation/Foundation.h>
#import <SharedWithYouCore/SWDefines.h>
#import <SharedWithYou/SWHighlight.h>
//#import <SharedWithYou/SWCollaborationHighlight.h>

NS_ASSUME_NONNULL_BEGIN
@class SWHighlight;
@class SWHighlightCenter;
@class SWCollaborationHighlight;

/*!
     @protocol SWHighlightCenterDelegate
     @abstract The delegate is notified when there are changes to the list of surfaced highlights, or when the enablement settings change.
 */
@protocol SWHighlightCenterDelegate <NSObject>

@required
/*!
    @abstract Notifies the delegate that the list, or rank order of surfaced highlights has changed.
    @discussion When this method is called, it is the app's responsibility to update any displayed highlights to match the updated list. Only the highlights provided should have an indication of having been shared. If no highlights are provided in the list, any links previously indicated as shared should be removed. The array is a priority-ordered list, where the first element in the array is deemed to be most relevant to the user at the time this method is called. The list of provided highlights will be empty if there are no highlights, or when the user has not given permission for a particular app to display highlights.
 */
- (void)highlightCenterHighlightsDidChange:(SWHighlightCenter *)highlightCenter;

@end

/*!
     @class SWHighlightCenter
     @abstract Provides the application with a priority-ordered list of universal links which have been shared with the current user.
     @discussion The system decides which links should be surfaced. The app is responsible for updating its UI to reflect the latest provided list.
 */
SW_EXTERN @interface SWHighlightCenter : NSObject

/*!
    @abstract The highlight center's delegate
 */
@property (nullable, weak, nonatomic, readwrite) id<SWHighlightCenterDelegate> delegate;

@property (copy, nonatomic, readonly) NSArray<SWHighlight *> *highlights;

/*!
    @abstract Localized title to display with a collection of highlights
    @discussion Use this string as the title for a collection of shared highlight links displayed to the user.
 */
@property (class, nonatomic, readonly) NSString *highlightCollectionTitle;

@end

NS_ASSUME_NONNULL_END
