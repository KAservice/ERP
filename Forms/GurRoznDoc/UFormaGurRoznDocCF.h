#ifndef UFormaGurRoznDocCFH                  
#define UFormaGurRoznDocCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaGurRoznDocCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaGurRoznDocCF();                                                           
   ~TFormaGurRoznDocCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
