#ifndef UREM_FormaDocZakazPostCFH                  
#define UREM_FormaDocZakazPostCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaDocZakazPostCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaDocZakazPostCF();                                                           
   ~TREM_FormaDocZakazPostCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
