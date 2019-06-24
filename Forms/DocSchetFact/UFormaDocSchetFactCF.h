#ifndef UFormaDocSchetFactCFH                  
#define UFormaDocSchetFactCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaDocSchetFactCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaDocSchetFactCF();                                                           
   ~TFormaDocSchetFactCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
