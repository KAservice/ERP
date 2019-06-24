#ifndef UDMDocSchetFactCFH                  
#define UDMDocSchetFactCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMDocSchetFactCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMDocSchetFactCF();                                                           
   ~TDMDocSchetFactCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
