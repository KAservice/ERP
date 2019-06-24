#ifndef UDMDocPKORoznCFH                  
#define UDMDocPKORoznCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMDocPKORoznCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMDocPKORoznCF();                                                           
   ~TDMDocPKORoznCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
