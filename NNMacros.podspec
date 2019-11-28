Pod::Spec.new do |s|

  s.name          = "NNMacros"
  s.version       = "2.3.2"
  s.summary       = "NNMacros: Macros used in Objective-C development"

  s.description   = <<-DESC
                   NNMacros: Macros used in Objective-C development.
                   DESC

  s.homepage      = "https://github.com/amisare/NNMacros"
  s.license       = { :type => "MIT", :file => "LICENSE" }
  s.author        = { "Haijun Gu" => "243297288@qq.com" }
  s.social_media_url        = "https://www.jianshu.com/u/9df9f28ff266"

  s.source        = { :git => "https://github.com/amisare/NNMacros.git", :tag => s.version.to_s }
  s.ios.deployment_target   = '6.0'
  s.requires_arc  = true
  s.static_framework = true

  s.source_files  = 'NNMacros/NNMacros/*.{h,m}', 'NNMacros/NNMacros/CocoapodsFix/*.{h,m}'

  s.default_subspec         = 'Bases'
  s.subspec 'Bases' do |ss|
    ss.source_files         = 'NNMacros/NNMacros/Bases/*.{h,m}'
  end

end
