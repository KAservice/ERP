#ifndef UFormaElementaSprDocKlientCFH                  
#define UFormaElementaSprDocKlientCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaSprDocKlientCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaSprDocKlientCF();                                                           
   ~TFormaElementaSprDocKlientCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
