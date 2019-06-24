#ifndef UFormaDocRKORoznCFH                  
#define UFormaDocRKORoznCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaDocRKORoznCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaDocRKORoznCF();                                                           
   ~TFormaDocRKORoznCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
