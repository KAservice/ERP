#ifndef UDMSprVidKlientCFH                  
#define UDMSprVidKlientCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprVidKlientCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprVidKlientCF();                                                           
   ~TDMSprVidKlientCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
