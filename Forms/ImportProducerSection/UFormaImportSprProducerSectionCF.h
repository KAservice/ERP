#ifndef UFormaImportSprProducerSectionCFH                  
#define UFormaImportSprProducerSectionCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaImportSprProducerSectionCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaImportSprProducerSectionCF();                                                           
   ~TFormaImportSprProducerSectionCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
