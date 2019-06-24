#ifndef UFormaDocRepKKMCFH                  
#define UFormaDocRepKKMCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaDocRepKKMCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaDocRepKKMCF();                                                           
   ~TFormaDocRepKKMCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
