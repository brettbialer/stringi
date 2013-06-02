/* This file is part of the 'stringi' library.
 * 
 * Copyright 2013 Marek Gagolewski, Bartek Tartanus, Marcin Bujarski
 * 
 * 'stringi' is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * 'stringi' is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with 'stringi'. If not, see <http://www.gnu.org/licenses/>.
 */
 
#ifndef __charclass_h
#define __charclass_h





/**
 * Class for testing whether a character falls into a given character class
 * (i.e. has a given binary property or is in general unicode category).
 * 
 * @version 0.1 (Marek Gagolewski)
 */
struct CharClass {
   
   private:
   
      UProperty     binprop;    //< Unicode Binary Property, -1 if not used
      UCharCategory gencat;     //< Unicode General Category, -1 if not used
   
   
      static const char** binprop_names;       //< textual identifiers binary properties
      static const UProperty* binprop_code;    //< corresponding codes for \code{binprop_names}
   
   
   public:
   
      
   
      CharClass() { binprop = (UProperty)-1; gencat = (UCharCategory)-1; }
      CharClass(SEXP charclass);
      inline bool isNA() { return (binprop == (UProperty)-1 && gencat == (UCharCategory)-1); }

      int test(UChar32 c);

};

#endif