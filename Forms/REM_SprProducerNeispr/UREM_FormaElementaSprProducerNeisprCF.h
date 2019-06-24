#ifndef UREM_FormaElementaSprProducerNeisprCFH                  
#define UREM_FormaElementaSprProducerNeisprCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaElementaSprProducerNeisprCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaElementaSprProducerNeisprCF();                                                           
   ~TREM_FormaElementaSprProducerNeisprCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
