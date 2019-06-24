#ifndef UDMDocRepKKMCFH                  
#define UDMDocRepKKMCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMDocRepKKMCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMDocRepKKMCF();                                                           
   ~TDMDocRepKKMCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
