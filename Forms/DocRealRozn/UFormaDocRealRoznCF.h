#ifndef UFormaDocRealRoznCFH                  
#define UFormaDocRealRoznCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaDocRealRoznCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaDocRealRoznCF();                                                           
   ~TFormaDocRealRoznCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
