#ifndef UFormaDocRealCFH                  
#define UFormaDocRealCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaDocRealCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaDocRealCF();                                                           
   ~TFormaDocRealCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
