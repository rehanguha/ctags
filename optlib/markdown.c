/*
 * Generated by ./misc/optlib2c from optlib/markdown.ctags, Don't edit this manually.
 */
#include "general.h"
#include "parse.h"
#include "routines.h"
#include "field.h"
#include "xtag.h"


static void initializeMarkdownParser (const langType language)
{

	addLanguageRegexTable (language, "main");
	addLanguageRegexTable (language, "sharp");

	addLanguageTagMultiTableRegex (language, "main",
	                               "^#",
	                               "", "", "{tjump=sharp}{_advanceTo=0start}", NULL);
	addLanguageTagMultiTableRegex (language, "main",
	                               "^([^\n]+)[\n]=+[\n]",
	                               "\\1", "c", "{_field=sectionMarker:=}", NULL);
	addLanguageTagMultiTableRegex (language, "main",
	                               "^([^\n]+)[\n]-+[\n]",
	                               "\\1", "s", "{_field=sectionMarker:-}", NULL);
	addLanguageTagMultiTableRegex (language, "main",
	                               "^[^\n]+[\n]",
	                               "", "", "", NULL);
	addLanguageTagMultiTableRegex (language, "main",
	                               "^[\n]+",
	                               "", "", "", NULL);
	addLanguageTagMultiTableRegex (language, "main",
	                               "^[^\n]+",
	                               "", "", "", NULL);
	addLanguageTagMultiTableRegex (language, "sharp",
	                               "^#[ \t]+([^\n]+)([ \t]+#+)[\n]",
	                               "\\1", "c", "{_field=sectionMarker:##}{tjump=main}", NULL);
	addLanguageTagMultiTableRegex (language, "sharp",
	                               "^##[ \t]+([^\n]+)([ \t]+#+)[\n]",
	                               "\\1", "s", "{_field=sectionMarker:##}{tjump=main}", NULL);
	addLanguageTagMultiTableRegex (language, "sharp",
	                               "^###[ \t]+([^\n]+)([ \t]+#+)[\n]",
	                               "\\1", "S", "{_field=sectionMarker:##}{tjump=main}", NULL);
	addLanguageTagMultiTableRegex (language, "sharp",
	                               "^####[ \t]+([^\n]+)([ \t]+#+)[\n]",
	                               "\\1", "t", "{_field=sectionMarker:##}{tjump=main}", NULL);
	addLanguageTagMultiTableRegex (language, "sharp",
	                               "^#####[ \t]+([^\n]+)([ \t]+#+)[\n]",
	                               "\\1", "T", "{_field=sectionMarker:##}{tjump=main}", NULL);
	addLanguageTagMultiTableRegex (language, "sharp",
	                               "^######[ \t]+([^\n]+)([ \t]+#+)[\n]",
	                               "\\1", "u", "{_field=sectionMarker:##}{tjump=main}", NULL);
	addLanguageTagMultiTableRegex (language, "sharp",
	                               "^#[ \t]+([^\n]+)[\n]",
	                               "\\1", "c", "{_field=sectionMarker:#}{tjump=main}", NULL);
	addLanguageTagMultiTableRegex (language, "sharp",
	                               "^##[ \t]+([^\n]+)[\n]",
	                               "\\1", "s", "{_field=sectionMarker:#}{tjump=main}", NULL);
	addLanguageTagMultiTableRegex (language, "sharp",
	                               "^###[ \t]+([^\n]+)[\n]",
	                               "\\1", "S", "{_field=sectionMarker:#}{tjump=main}", NULL);
	addLanguageTagMultiTableRegex (language, "sharp",
	                               "^####[ \t]+([^\n]+)[\n]",
	                               "\\1", "t", "{_field=sectionMarker:#}{tjump=main}", NULL);
	addLanguageTagMultiTableRegex (language, "sharp",
	                               "^#####[ \t]+([^\n]+)[\n]",
	                               "\\1", "T", "{_field=sectionMarker:#}{tjump=main}", NULL);
	addLanguageTagMultiTableRegex (language, "sharp",
	                               "^######[ \t]+([^\n]+)[\n]",
	                               "\\1", "u", "{_field=sectionMarker:#}{tjump=main}", NULL);
	addLanguageTagMultiTableRegex (language, "sharp",
	                               "^[^\n]+[\n]",
	                               "", "", "{tjump=main}", NULL);
	addLanguageTagMultiTableRegex (language, "sharp",
	                               "^[\n]+",
	                               "", "", "{tjump=main}", NULL);
	addLanguageTagMultiTableRegex (language, "sharp",
	                               "^[^\n]+",
	                               "", "", "{tjump=main}", NULL);
}

extern parserDefinition* MarkdownParser (void)
{
	static const char *const extensions [] = {
		"md",
		"markdown",
		NULL
	};

	static const char *const aliases [] = {
		NULL
	};

	static const char *const patterns [] = {
		NULL
	};

	static kindDefinition MarkdownKindTable [] = {
		{
		  true, 'c', "chapter", "chapsters",
		},
		{
		  true, 's', "section", "sections",
		},
		{
		  true, 'S', "subsection", "subsections",
		},
		{
		  true, 't', "subsubsection", "subsubsections",
		},
		{
		  true, 'T', "l4subsection", "level 4 subsections",
		},
		{
		  true, 'u', "l5subsection", "level 5 subsections",
		},
	};
	static fieldDefinition MarkdownFieldTable [] = {
		{
		  .enabled     = false,
		  .name        = "sectionMarker",
		  .description = "character used for declaring section(#, ##, =, or -)",
		},
	};

	parserDefinition* const def = parserNew ("Markdown");

	def->enabled       = true;
	def->extensions    = extensions;
	def->patterns      = patterns;
	def->aliases       = aliases;
	def->method        = METHOD_NOT_CRAFTED|METHOD_REGEX;
	def->kindTable     = MarkdownKindTable;
	def->kindCount     = ARRAY_SIZE(MarkdownKindTable);
	def->fieldTable    = MarkdownFieldTable;
	def->fieldCount    = ARRAY_SIZE(MarkdownFieldTable);
	def->initialize    = initializeMarkdownParser;

	return def;
}
