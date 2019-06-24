#ifndef UFormaDocRevCFH                  
#define UFormaDocRevCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaDocRevCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaDocRevCF();                                                           
   ~TFormaDocRevCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
