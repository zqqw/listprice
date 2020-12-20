#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <argp.h>
//#define DBG

char* iso4217[] =
{
  "GBX", //United Kingdom pence
  "EUR", //Euro Member Countries
  "USD", //United States Dollar
  "CAD", //Canada Dollar
  "SEK", //Sweden Krona
  "NOK", //Norway Krone
  "AED", //United Arab Emirates Dirham
  "AFN", //Afghanistan Afghani
  "ALL", //Albania Lek
  "AMD", //Armenia Dram
  "ANG", //Netherlands Antilles Guilder
  "AOA", //Angola Kwanza
  "ARS", //Argentina Peso
  "AUD", //Australia Dollar
  "AWG", //Aruba Guilder
  "AZN", //Azerbaijan Manat
  "BAM", //Bosnia and Herzegovina Convertible Mark
  "BBD", //Barbados Dollar
  "BDT", //Bangladesh Taka
  "BGN", //Bulgaria Lev
  "BHD", //Bahrain Dinar
  "BIF", //Burundi Franc
  "BMD", //Bermuda Dollar
  "BND", //Brunei Darussalam Dollar
  "BOB", //Bolivia Bolíviano
  "BRL", //Brazil Real
  "BSD", //Bahamas Dollar
  "BTN", //Bhutan Ngultrum
  "BWP", //Botswana Pula
  "BYN", //Belarus Ruble
  "BZD", //Belize Dollar
  "CDF", //Congo/Kinshasa Franc
  "CHF", //Switzerland Franc
  "CLP", //Chile Peso
  "CNY", //China Yuan Renminbi
  "COP", //Colombia Peso
  "CRC", //Costa Rica Colon
  "CUC", //Cuba Convertible Peso
  "CUP", //Cuba Peso
  "CVE", //Cape Verde Escudo
  "CZK", //Czech Republic Koruna
  "DJF", //Djibouti Franc
  "DKK", //Denmark Krone
  "DOP", //Dominican Republic Peso
  "DZD", //Algeria Dinar
  "EGP", //Egypt Pound
  "ERN", //Eritrea Nakfa
  "ETB", //Ethiopia Birr
  "FJD", //Fiji Dollar
  "FKP", //Falkland Islands (Malvinas) Pound
  "GBP", //United Kingdom Pound
  "GEL", //Georgia Lari
  "GGP", //Guernsey Pound
  "GHS", //Ghana Cedi
  "GIP", //Gibraltar Pound
  "GMD", //Gambia Dalasi
  "GNF", //Guinea Franc
  "GTQ", //Guatemala Quetzal
  "GYD", //Guyana Dollar
  "HKD", //Hong Kong Dollar
  "HNL", //Honduras Lempira
  "HRK", //Croatia Kuna
  "HTG", //Haiti Gourde
  "HUF", //Hungary Forint
  "IDR", //Indonesia Rupiah
  "ILS", //Israel Shekel
  "IMP", //Isle of Man Pound
  "INR", //India Rupee
  "IQD", //Iraq Dinar
  "IRR", //Iran Rial
  "ISK", //Iceland Krona
  "JEP", //Jersey Pound
  "JMD", //Jamaica Dollar
  "JOD", //Jordan Dinar
  "JPY", //Japan Yen
  "KES", //Kenya Shilling
  "KGS", //Kyrgyzstan Som
  "KHR", //Cambodia Riel
  "KMF", //Comorian Franc
  "KPW", //Korea (North) Won
  "KRW", //Korea (South) Won
  "KWD", //Kuwait Dinar
  "KYD", //Cayman Islands Dollar
  "KZT", //Kazakhstan Tenge
  "LAK", //Laos Kip
  "LBP", //Lebanon Pound
  "LKR", //Sri Lanka Rupee
  "LRD", //Liberia Dollar
  "LSL", //Lesotho Loti
  "LYD", //Libya Dinar
  "MAD", //Morocco Dirham
  "MDL", //Moldova Leu
  "MGA", //Madagascar Ariary
  "MKD", //Macedonia Denar
  "MMK", //Myanmar (Burma) Kyat
  "MNT", //Mongolia Tughrik
  "MOP", //Macau Pataca
  "MRU", //Mauritania Ouguiya
  "MUR", //Mauritius Rupee
  "MVR", //Maldives (Maldive Islands) Rufiyaa
  "MWK", //Malawi Kwacha
  "MXN", //Mexico Peso
  "MYR", //Malaysia Ringgit
  "MZN", //Mozambique Metical
  "NAD", //Namibia Dollar
  "NGN", //Nigeria Naira
  "NIO", //Nicaragua Cordoba
  "NPR", //Nepal Rupee
  "NZD", //New Zealand Dollar
  "OMR", //Oman Rial
  "PAB", //Panama Balboa
  "PEN", //Peru Sol
  "PGK", //Papua New Guinea Kina
  "PHP", //Philippines Peso
  "PKR", //Pakistan Rupee
  "PLN", //Poland Zloty
  "PYG", //Paraguay Guarani
  "QAR", //Qatar Riyal
  "RON", //Romania Leu
  "RSD", //Serbia Dinar
  "RUB", //Russia Ruble
  "RWF", //Rwanda Franc
  "SAR", //Saudi Arabia Riyal
  "SBD", //Solomon Islands Dollar
  "SCR", //Seychelles Rupee
  "SDG", //Sudan Pound
  "SGD", //Singapore Dollar
  "SHP", //Saint Helena Pound
  "SLL", //Sierra Leone Leone
  "SOS", //Somalia Shilling
  "SPL", // *Seborga Luigino
  "SRD", //Suriname Dollar
  "STN", //São Tomé and Príncipe Dobra
  "SVC", //El Salvador Colon
  "SYP", //Syria Pound
  "SZL", //eSwatini Lilangeni
  "THB", //Thailand Baht
  "TJS", //Tajikistan Somoni
  "TMT", //Turkmenistan Manat
  "TND", //Tunisia Dinar
  "TOP", //Tonga Pa'anga
  "TRY", //Turkey Lira
  "TTD", //Trinidad and Tobago Dollar
  "TVD", //Tuvalu Dollar
  "TWD", //Taiwan New Dollar
  "TZS", //Tanzania Shilling
  "UAH", //Ukraine Hryvnia
  "UGX", //Uganda Shilling
  "UYU", //Uruguay Peso
  "UZS", //Uzbekistan Som
  "VEF", //Venezuela Bolívar
  "VND", //Viet Nam Dong
  "VUV", //Vanuatu Vatu
  "WST", //Samoa Tala
  "XAF", //Communauté Financière Africaine (BEAC) CFA Franc BEAC
  "XCD", //East Caribbean Dollar
  "XDR", //International Monetary Fund (IMF) Special Drawing Rights
  "XOF", //Communauté Financière Africaine (BCEAO) Franc
  "XPF", //Comptoirs Français du Pacifique (CFP) Franc
  "YER", //Yemen Rial
  "ZAR", //South Africa Rand
  "ZMW", //Zambia Kwacha
  "ZWD", //Zimbabwe Dollar
  NULL
};

int main (int argc, char *argv[]);
int process_string (char *str1, char *str2, size_t numbyte, int gbx_only);
int strlen_utf8(char *mystr);
static error_t parse_opt (int key, char *arg, struct argp_state *state);

struct arguments
{
  char *args[2];
  int gbx_only;
};

const char *argp_program_version = "listprice 3.0.0";

const char *argp_program_bug_address = "<www.cxperimental.weebly.com>";

static char args_doc[] = "INFILE OUTFILE";

static char doc[] =
("listprice : edits data copy-pasted from London Stock Exchange searches\n\
Examples of use:\n\
$ listprice infile.txt outfile.txt  :  read infile, write (edited) to outfile \n\
$ listprice -a infile.txt outfile.txt : use iso4217 list as key, not just GBX\n");

static struct argp_option options[] = {
  {"all", 'a', 0, 0, ("use all iso4217 codes to find lines"), 0},
  {0, 0, 0, 0, 0, 0}
};

static struct argp argp = {options, parse_opt, args_doc, doc, NULL, 0, 0};

static error_t
parse_opt (int key, char *arg, struct argp_state *state)
{
  struct arguments *arguments = state->input;

  switch (key)
    {
    case 'a':
      arguments->gbx_only = 0;
      break;
    case ARGP_KEY_ARG:
      if (state->arg_num >= 2)
	{
	  argp_usage(state);
	}
      arguments->args[state->arg_num] = arg;
      break;
    case ARGP_KEY_END:
      if (state->arg_num < 2)
	{
	  argp_usage (state);
	}
      break;
    default:
      return ARGP_ERR_UNKNOWN;
    }
  return 0;
}

int
main (int argc, char *argv[])
{
  FILE *instream, *outstream;
  char *string1, *string2;
  size_t nbytes = 10;
  ssize_t glval = 0;
  int err;
  struct arguments arguments;

  arguments.gbx_only = 1;
  argp_parse (&argp, argc, argv, 0, 0, &arguments);

  instream = fopen (arguments.args[0], "r");
  if (instream == NULL)
    {
      printf ("Could not open %s : Usage :\n", argv[1]);
      printf ("listprice [/path/]inputfile.txt [/path/]outputfile.txt\n");
      exit (EXIT_FAILURE);
    }
#ifdef DBG
  printf ("instream = %p\n", (void*) instream);
#endif
  outstream = fopen (arguments.args[1], "ax");
  if (outstream == NULL)
    {
      printf ("Can't open %s : Usage :\n", argv[2]);
      printf ("listprice [/path/]inputfile.txt [/path/]outputfile.txt\n");
      printf ("Won't overwrite existing outputfile.txt\n");
      exit (EXIT_FAILURE);
    }

  string1 = (char *) malloc (nbytes + 1);
//Loop through each line of the input file
  do
    {
      glval = getline (&string1, &nbytes, instream);
#ifdef DBG
      printf ("%s\n", string1);
#endif
      string2 = (char *) malloc (nbytes + 100); // allow for extra spaces
      err = process_string (string1, string2, nbytes, arguments.gbx_only);
      if (err == 1) continue;
      printf ("%s\n", string2);
      fprintf (outstream, "%s\n", string2);
    }
  while (glval != -1);

  free (string1);
  free (string2);
  fclose (instream);
  fclose (outstream);
  return 0;
}

int
process_string (char *str1, char *str2, size_t numbyte, int gbx_only)
{
  char *token, *to, *to2, *name_string;
  const char dl[] = " 	/n";
  int i = 0, flag = 0, found = 0;
  size_t size1, tmp;

//Get the first token for the ticker code
  to = str2;
  token = strtok (str1, dl);
  if (token == NULL)
    {
#ifdef DBG
      puts ("First token == NULL");
#endif
      return (1);
    }
  size1 = strlen_utf8 (token);
  to = stpncpy (to, token, 8);
//Make str2 contain 8 characters by adding spaces
  if (size1 < 8)
    {
      for (tmp = (8 - size1) ; tmp != 0 ; tmp--)
        {
          to = stpncpy (to, " ", 2);
        }
    }
  name_string = (char *) malloc (numbyte + 100); // allow for extra spaces
  to2 = name_string;
  for (flag = 0 ; flag < 20 && found != 1; flag++)
    {
      token = strtok (NULL, dl);
      if (token == NULL)
        {
#ifdef DBG
          puts ("token == NULL in name substring");
#endif
          free (name_string);
          return (1);
        }
#ifdef DBG
      printf ("Substring token %d = %s\n", flag, token);
#endif
      if (strlen(token) == 3)
        {
          if (gbx_only)
            {
              if (!(strncmp (token, "GBX", 3)))
                {
                  found = 1;
                }
            }
          else
            {
              for (i = 0; iso4217[i] != NULL; i++)
                {
                  if (!(strncmp (token, iso4217[i], 3)))
                    {
                      found = 1;
                      break;
                    }
                }
            }
        }
//Copy the token to name_string and add a space
      if (found != 1)
        {
          to2 = stpncpy (to2, token, 33);
          to2 = stpncpy (to2, " ", 2);
        }
    }
//Is this a valid line including an iso 4217 code ? Add it to str2 if it is.
  if (!found)
    {
#ifdef DBG
      puts ("Didn't find an iso 4217 code");
#endif
      free (name_string);
      return (1);
    }
  size1 = strlen_utf8 (name_string);
#ifdef DBG
  printf ("size1 = %d\nstrlen_utf8 to = %d\n", (int)size1, (int)strlen_utf8 (to));
#endif
  to = stpncpy (to, name_string, 50);
//Make this field 50 characters long by adding spaces if needed
  if (size1 < 50)
    {
      for (tmp = (50 - size1) ; tmp != 0 ; tmp --)
        {
          to = stpncpy (to, " ", 2);
        }
    }
//Add a space
  to = stpncpy (to, " ", 2);
//Add the market cap
  token = strtok (NULL, dl);
  if (token == NULL)
    {
#ifdef DBG
      puts ("Last token == NULL");
#endif
      free (name_string);
      return (1);
    }
  size1 = strlen_utf8 (token);
  to = stpncpy (to, token, 10);
//Make str2 contain 10 characters by adding spaces
  if (size1 < 10)
    {
      for (tmp = (10 - size1) ; tmp != 0 ; tmp--)
        {
          to = stpncpy (to, " ", 2);
        }
    }
  to = stpncpy (to, " ", 2);
//Add iso code
  to = stpncpy (to, iso4217[i], 3);
  to = stpncpy (to, " ", 2);
//Add price
  token = strtok (NULL, dl);
  if (token == NULL)
    {
#ifdef DBG
      puts ("Last token == NULL");
#endif
      free (name_string);
      return (1);
    }
#ifdef DBG
  printf ("Price = %s\n", token);
#endif
  to = stpncpy (to, token, 10);
  to = stpncpy (to, " ", 2);
  free (name_string);
  return (0);
}

//'£' is 2 bytes in UTF8
int strlen_utf8(char *mystr) {
  int count = 0, len = 0;
  while (mystr[count])
    {
      if ((mystr[count] & 0xc0) != 0x80) len++;
      count++;
    }
  return len;
}
