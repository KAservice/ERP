#ifndef UFormaImportSprProducerNomCFH                  
#define UFormaImportSprProducerNomCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaImportSprProducerNomCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaImportSprProducerNomCF();                                                           
   ~TFormaImportSprProducerNomCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
