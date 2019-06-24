#ifndef UDMSprKKMCFH                  
#define UDMSprKKMCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprKKMCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprKKMCF();                                                           
   ~TDMSprKKMCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
