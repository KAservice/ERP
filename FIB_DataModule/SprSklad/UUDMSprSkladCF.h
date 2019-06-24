#ifndef UUDMSprSkladCFH                  
#define UUDMSprSkladCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TUDMSprSkladCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TUDMSprSkladCF();                                                           
   ~TUDMSprSkladCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
