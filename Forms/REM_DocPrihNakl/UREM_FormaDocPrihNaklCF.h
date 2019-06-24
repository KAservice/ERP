#ifndef UREM_FormaDocPrihNaklCFH                  
#define UREM_FormaDocPrihNaklCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaDocPrihNaklCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaDocPrihNaklCF();                                                           
   ~TREM_FormaDocPrihNaklCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
