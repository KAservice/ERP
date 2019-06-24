#ifndef UFormaImportSprProducerNeisprCFH                  
#define UFormaImportSprProducerNeisprCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaImportSprProducerNeisprCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaImportSprProducerNeisprCF();                                                           
   ~TFormaImportSprProducerNeisprCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
