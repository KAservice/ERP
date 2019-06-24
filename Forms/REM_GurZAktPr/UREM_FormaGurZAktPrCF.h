#ifndef UREM_FormaGurZAktPrCFH                  
#define UREM_FormaGurZAktPrCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaGurZAktPrCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaGurZAktPrCF();                                                           
   ~TREM_FormaGurZAktPrCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
