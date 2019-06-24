#ifndef UFormaImportDocPrihNaklCFH                  
#define UFormaImportDocPrihNaklCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaImportDocPrihNaklCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaImportDocPrihNaklCF();                                                           
   ~TFormaImportDocPrihNaklCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
