#include <stdio.h>
#include <stdlib.h>
#include <sys/timeb.h>
#include "katana.h"

/*
g++ css-parser.cpp `pkg-config --cflags --libs katana`
./a.out test.css

eg : test.css:

    hr {color: sienna;}
    p {margin-left: 20px;color:red;}
    body {background-image: url("images/back40.gif");}
    div {color:black;}
*/

#define StopWatchBegin(begin) \
    struct timeb t1;          \
    ftime(&t1);

#define StopWatchEnd(begin) \
    struct timeb t2;        \
    ftime(&t2);             \
    printf("<" #begin "> costs %dms.\n", (t2.millitm - t1.millitm));

int i = 0;

void apply_rule(KatanaArray *Properties)
{
    for (long i = 0; i < Properties->length; i++)
    {
        auto prop = (KatanaDeclaration *)Properties->data[i];
        printf("Set property \"%s\"  with %d values\n", prop->property, prop->values->length);
        for (long v = 0; v < prop->values->length; v++)
        {
            auto value = (KatanaValue *)prop->values->data[v];
            // printf("unit is %d\n", value->unit);
            switch (value->unit)
            {
            case KATANA_VALUE_URI:
            {
                printf("KATANA_VALUE_URI properties value is : %s\n", value->string);
                break;
            }
            case KATANA_VALUE_IDENT:
            {
                printf("KATANA_VALUE_IDENT properties value is : %s\n", value->string);
                break;
            }
            case KATANA_VALUE_STRING:
            {
                printf("KATANA_VALUE_STRING properties value is : %s\n", value->string);
                break;
            }
            case KATANA_VALUE_PX:
            {
                printf("KATANA_VALUE_PX properties value is : %dpx\n", value->string);
                break;
            }
            }
        }
    }
}
void parse_rule(KatanaRule *Rule)
{
    if (Rule == NULL)
    {
        exit;
    }
    switch (Rule->type)
    {
    case KatanaRuleStyle:
    {
        auto sr = (KatanaStyleRule *)Rule;
        for (long i = 0; i < sr->selectors->length; ++i)
        {
            auto sel = (KatanaSelector *)sr->selectors->data[i];
            switch (sel->match)
            {
            case KatanaSelectorMatchTag:
                printf("Processing selector is: %s\n", (sel->tag) ? sel->tag->local : "UNNAMED");
                apply_rule(sr->declarations);
                break;
            case KatanaSelectorMatchId:
                break;
            case KatanaSelectorMatchClass:
                printf("Processing class selector: %s\n", (sel->data) ? sel->data->value : "UNNAMED");
                break;
            case KatanaSelectorMatchPseudoClass: // E.g. a:link
                break;
            case KatanaSelectorMatchPseudoElement:
                break;
            case KatanaSelectorMatchPagePseudoClass:
                break;
            case KatanaSelectorMatchAttributeExact:
                break;
            case KatanaSelectorMatchAttributeSet:
                break;
            case KatanaSelectorMatchAttributeList:
                break;
            case KatanaSelectorMatchAttributeHyphen:
                break;
            case KatanaSelectorMatchAttributeContain:
                break;
            case KatanaSelectorMatchAttributeBegin:
                break;
            case KatanaSelectorMatchAttributeEnd:
                break;
            case KatanaSelectorMatchUnknown:
                break;
            }
        }
    }
    }
}

void dump_stylesheet(const char *filename)
{
    FILE *fp = fopen(filename, "r");
    if (!fp)
    {
        printf("File %s not found!\n", filename);
        exit(0);
    }
    StopWatchBegin(KatanaParseFile);
    KatanaOutput *output = katana_parse_in(fp);
    StopWatchEnd(KatanaParseFile);
    KatanaStylesheet *sheet = output->stylesheet;
    printf("sheet->imports:%d\n", sheet->imports.length);
    printf("sheet->rules:%d\n", sheet->rules.length);
    printf("======================\n");
    for (long i = 0; i < sheet->rules.length; ++i)
    {
        if (sheet->rules.data[i])
        {
            KatanaRule *item = (KatanaRule *)sheet->rules.data[i];
            printf("name : %s\n", item->name);
            parse_rule(item);
            printf("======================\n");
        }
    }
    // katana_dump_output(output);
    katana_destroy_output(output);
}

int main(int argc, const char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: css_dump <CSS filename>.\n");
        exit(0);
    }
    dump_stylesheet(argv[1]);
    return 0;
}