#ifndef UDMSprKlientDopFisLCFH                  
#define UDMSprKlientDopFisLCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprKlientDopFisLCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprKlientDopFisLCF();                                                           
   ~TDMSprKlientDopFisLCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
