#ifndef UDMSprDocKlientCFH                  
#define UDMSprDocKlientCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprDocKlientCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprDocKlientCF();                                                           
   ~TDMSprDocKlientCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
