#ifndef UDMDocRealCFH                  
#define UDMDocRealCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMDocRealCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMDocRealCF();                                                           
   ~TDMDocRealCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
