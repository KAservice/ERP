#ifndef UFormaElementaSprDogovorCFH                  
#define UFormaElementaSprDogovorCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaSprDogovorCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaSprDogovorCF();                                                           
   ~TFormaElementaSprDogovorCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
