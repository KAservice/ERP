#ifndef UFormaImageEditorCFH                  
#define UFormaImageEditorCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaImageEditorCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaImageEditorCF();                                                           
   ~TFormaImageEditorCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
