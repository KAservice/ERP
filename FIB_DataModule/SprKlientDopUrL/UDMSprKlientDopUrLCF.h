#ifndef UDMSprKlientDopUrLCFH                  
#define UDMSprKlientDopUrLCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprKlientDopUrLCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprKlientDopUrLCF();                                                           
   ~TDMSprKlientDopUrLCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
