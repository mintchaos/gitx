//
//  PBGitRepository.h
//  GitTest
//
//  Created by Pieter de Bie on 13-06-08.
//  Copyright 2008 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "PBGitRevList.h"
#import "PBGitRevSpecifier.h"
#import "PBGitConfig.h"

extern NSString* PBGitRepositoryErrorDomain;

@interface PBGitRepository : NSDocument {
	PBGitRevList* revisionList;
	PBGitConfig *config;

	BOOL hasChanged;
	NSMutableArray *branches;
	PBGitRevSpecifier *currentBranch;
	NSMutableDictionary *refs;

	PBGitRevSpecifier *_headRef; // Caching
}

- (NSFileHandle*) handleForCommand:(NSString*) cmd;
- (NSFileHandle*) handleForArguments:(NSArray*) args;
- (NSFileHandle *) handleInWorkDirForArguments:(NSArray *)args;
- (NSString*) outputForCommand:(NSString*) cmd;
- (NSString *)outputForCommand:(NSString *)str retValue:(int *)ret;
- (NSString *)outputForArguments:(NSArray *)arguments inputString:(NSString *)input retValue:(int *)ret;
- (NSString*) outputForArguments:(NSArray*) args;
- (NSString*) outputForArguments:(NSArray*) args retValue:(int *)ret;
- (NSString *)outputInWorkdirForArguments:(NSArray*) arguments;
- (NSString *)outputInWorkdirForArguments:(NSArray*) arguments retValue:(int *)ret;

- (NSString *)workingDirectory;

- (BOOL) reloadRefs;
- (void) addRef:(PBGitRef *)ref fromParameters:(NSArray *)params;
- (void) lazyReload;
- (PBGitRevSpecifier*) headRef;

- (void) readCurrentBranch;
- (PBGitRevSpecifier*) addBranch: (PBGitRevSpecifier*) rev;

- (NSString*) parseSymbolicReference:(NSString*) ref;
- (NSString*) parseReference:(NSString*) ref;

+ (NSURL*)gitDirForURL:(NSURL*)repositoryURL;
+ (NSURL*)baseDirForURL:(NSURL*)repositoryURL;

- (id) initWithURL: (NSURL*) path;
- (void) setup;

@property (assign) BOOL hasChanged;
@property (readonly) NSWindowController *windowController;
@property (readonly) PBGitConfig *config;
@property (retain) PBGitRevList* revisionList;
@property (assign) NSMutableArray* branches;
@property (assign) PBGitRevSpecifier *currentBranch;
@property (assign) NSMutableDictionary* refs;
@end
