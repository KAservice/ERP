#ifndef UFormaImportSprProducerDefectCFH                  
#define UFormaImportSprProducerDefectCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaImportSprProducerDefectCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaImportSprProducerDefectCF();                                                           
   ~TFormaImportSprProducerDefectCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
