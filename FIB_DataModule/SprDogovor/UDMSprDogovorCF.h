#ifndef UDMSprDogovorCFH                  
#define UDMSprDogovorCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprDogovorCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprDogovorCF();                                                           
   ~TDMSprDogovorCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
