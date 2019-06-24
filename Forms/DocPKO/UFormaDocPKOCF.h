#ifndef UFormaDocPKOCFH                  
#define UFormaDocPKOCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaDocPKOCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaDocPKOCF();                                                           
   ~TFormaDocPKOCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
