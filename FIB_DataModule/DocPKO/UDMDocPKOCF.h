#ifndef UDMDocPKOCFH                  
#define UDMDocPKOCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMDocPKOCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMDocPKOCF();                                                           
   ~TDMDocPKOCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
